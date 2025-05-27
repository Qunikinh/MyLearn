let load = document.getElementById("loading");
let gallery = document.getElementById("gallery");
const folderPath = 'pic/';
const imageFormat = 'jpg';
const images = document.querySelectorAll('#gallery img');
let big = document.getElementById("big");

load.addEventListener("click", function () {
    images.forEach((img) => {
        img.style = "display: block;"
        img.src = folderPath + img.id + '.' + imageFormat;
    })
})

images.forEach((img) => {
    img.addEventListener("click", function () {
        big.src = img.src;
    })
})