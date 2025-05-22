let now = new Date();
console.log(now);
let year = now.getFullYear();
let month = now.getMonth() + 1;
let date = now.getDate();
let day = now.getDay();
let today = `今天是${year}年${month}月${date}日,星期${day}`;
console.log(today);