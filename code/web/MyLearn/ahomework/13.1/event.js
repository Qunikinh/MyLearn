let div1 = document.getElementById("id1");
console.log(div1);

div1.addEventListener("click", function () {
    console.log("div1被点击了");
    div1.classList.remove("c4");
})

div1.addEventListener("click", function () {
    div1.classList.add("c2");
})
div1.addEventListener("mouseover", function () {
    console.log("div1被鼠标移入了");
    div1.classList.remove("c3");
})
div1.addEventListener("mouseout", function () {
    console.log("鼠标移出了div1")
    div1.classList.add("c3");
    div1.classList.remove("c2");
})
