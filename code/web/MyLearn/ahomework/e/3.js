let email = document.getElementById("email");
let password = document.getElementById("password");
let tishi = document.getElementById("tishi");
const ptn = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
let bt = document.getElementById("bt");
let msg = document.getElementById("massage");


bt.disabled = true;

msg.addEventListener("mouseenter", function () {
    if (email.value == 0 && password.value == 0) {
        tishi.innerText = "请输入内容";
        tishi.style = "color:grey;"
    }
    else {
        if (!ptn.test(email.value)) {
            if (email.value == 0) {
                tishi.innerText = "请输入邮箱...";
                tishi.style = "color:grey;"
            } else {
                tishi.innerText = "邮箱格式不正确";
                tishi.style = "color:red;"
            }
        } else {
            if (password.value.length != 6) {
                if (password.value == 0) {
                    tishi.innerText = "请输入密码...";
                    tishi.style = "color:grey;"
                } else {
                    tishi.innerText = "密码格式不正确";
                    tishi.style = "color:red;"
                    bt.disabled = true;
                }
            } else {
                tishi.innerText = "格式正确，请提交";
                tishi.style = "color:green;"
                bt.disabled = false;
            }
        }
    }
})

bt.addEventListener("click", function (event) {
    if (email.value == 0 || password.value == 0) {
        return;
    }
    else {
        tishi.innerText = "注册成功！";
    }
    event.preventDefault();
})
