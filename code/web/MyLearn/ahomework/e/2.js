const btn = document.getElementById('btn');
const body = document.body;
const div = document.querySelectorAll('div');

btn.addEventListener('click', function () {
    body.classList.toggle('dark');
    for (let i = 0; i < div.length; i++) {
        div[i].classList.toggle("b");
    }
});
