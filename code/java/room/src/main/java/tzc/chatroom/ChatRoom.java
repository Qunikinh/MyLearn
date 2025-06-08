package tzc.chatroom;

import com.google.gson.Gson;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

import javax.swing.*;
import java.awt.event.*;
import java.io.IOException;
import java.text.MessageFormat;
import java.util.List;
import java.util.Map;
import java.util.concurrent.TimeUnit;

public class ChatRoom {
    private JPanel panel1;
    private JTextField messageField;
    private JButton sendButton;
    private JList messageList;

    private DefaultListModel messageListModel;
    private String latestMessageTime="";
    private boolean stopFlag=false;
    private String ROOM_URL="http://chatroom.codingpython.cn/chatroom/messages?token={0}&room={1}";
    private static final String SEND_URL="http://chatroom.codingpython.cn/chatroom/chat?token={0}&room={1}&message={2}";
    private String token="";
    private String room="";

    public ChatRoom() {
        messageListModel = new DefaultListModel();
        messageList.setModel(messageListModel);
        sendButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String message = messageField.getText();
                OkHttpClient okhttpClient= new OkHttpClient();
                Request request = new Request.Builder().url(MessageFormat.format(SEND_URL,token,room,message)).build();
                try(Response response=okhttpClient.newCall(request).execute()) {
                    List<Map> latest20MessageList=getLatest20Messages();
                    updateMessageList(latest20MessageList);
                    messageList.ensureIndexIsVisible(messageListModel.size()-1);
                    messageField.setText("");
                } catch (IOException ex) {
                    // 显示错误消息给用户
                    JOptionPane.showMessageDialog(panel1,
                            "发送消息失败: " + ex.getMessage(),
                            "错误",
                            JOptionPane.ERROR_MESSAGE);
                }
            }
        });
    }

    private void updateMessageList(List<Map> messages) {
        if (messages == null) {
            // 可以选择显示错误消息或记录日志
            System.err.println("获取消息列表失败，列表为null");
            return;
        }

        String temptime = null;
        for (Map item : messages) {
            if (((String) item.get("created_at")).compareTo(latestMessageTime) > 0) {
                messageListModel.addElement(MessageFormat.format(
                        "{0}({1}) : {2}",
                        item.get("name"),
                        item.get("created_at"),
                        item.get("message")
                ));

                temptime = (String) item.get("created_at");
            }
        }
        if (temptime != null) {
            latestMessageTime = temptime;
        }
    }

    private List<Map> getLatest20Messages() {
        OkHttpClient httpClient = new OkHttpClient();
        Request request = new Request.Builder().url(MessageFormat.format(ROOM_URL, token, room)).build();
        List<Map> messages = null;
        try (Response response = httpClient.newCall(request).execute()) {
            if (!response.isSuccessful()) {
                throw new IOException("服务器返回错误: " + response);
            }

            String content = response.body().string();
            System.out.println(content);
            Gson gson = new Gson();
            Map responseJson = gson.fromJson(content, Map.class);

            // 检查响应是否包含messages字段
            if (responseJson != null && responseJson.containsKey("messages")) {
                messages = (List<Map>) responseJson.get("messages");
            } else {
                System.err.println("响应格式不符合预期: " + content);
            }
        } catch (IOException e) {
            e.printStackTrace();
            // 显示错误消息给用户
            SwingUtilities.invokeLater(() -> {
                JOptionPane.showMessageDialog(panel1,
                        "获取消息失败: " + e.getMessage(),
                        "错误",
                        JOptionPane.ERROR_MESSAGE);
            });
        }
        return messages;
    }

    public void run(String room, String token) {
        this.room = room;
        this.token = token;
        JFrame frame = new JFrame("ChatRoom");
        // 修正：使用当前实例的面板而不是创建新实例
        frame.setContentPane(panel1);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);

        // 这些初始化已经在构造函数中完成，不需要重复
        // messageListModel = new DefaultListModel();
        // messageList.setModel(messageListModel);

        frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                super.windowClosing(e);
                stopFlag = true;
            }
        });

        new Thread(() -> {
            while (!stopFlag) {
                try {
                    TimeUnit.SECONDS.sleep(1);
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                    break;
                }

                List<Map> latest20MessageList = getLatest20Messages();
                // 在事件调度线程中更新UI
                SwingUtilities.invokeLater(() -> {
                    updateMessageList(latest20MessageList);
                    messageList.ensureIndexIsVisible(messageListModel.size() - 1);
                });
            }
        }).start();
    }
}