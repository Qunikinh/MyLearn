function printNumber(from, to) {
    for (let i = from; i <= to; i++) {
        setTimeout(() => { console.log(i); }, (i - from) * 2000);
    }
    return;
}

window.onload = function () {
    let from = parseInt(prompt("请输入起始值"));
    let to = parseInt(prompt("请输入结束值"));
    printNumber(from, to);
}
