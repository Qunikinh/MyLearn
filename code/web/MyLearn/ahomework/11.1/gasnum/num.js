window.onload = function () {
    let num = Math.floor(Math.random() * 50 + 1);
    let c = 0;
    let t = 0;
    while (c < 5 && t == 0) {
        let a = parseInt(prompt("请输入一个1-50之间的整数"));
        if (a == num) {
            alert("恭喜你猜对了"); t = 1;
        }
        else if (a > num) {
            alert("猜大了");
        }
        else {
            alert("猜小了");
        }
        c++;
    }
    if (t == 0) {
        alert("很遗憾，你没有猜对，正确答案是" + num);
    }
}
