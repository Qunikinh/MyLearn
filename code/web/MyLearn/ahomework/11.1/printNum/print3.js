function printn(from, to) {
    let tmp = from;
    function pri() {
        if (tmp <= to) {
            console.log(tmp);
            tmp++;
            setTimeout(pri, 2000);
        }
    }
    pri();
}
printn(5, 9);
