
function printNumber(from, to) {
    let t = setInterval(() => {
        console.log(from++);
        if (from > to) {
            clearInterval(t);
        }
    }, 2000);
}

window.onload = function () {
    let from = parseInt(prompt("请输入起始值"));
    let to = parseInt(prompt("请输入结束值"));
    printNumber(from, to);
}