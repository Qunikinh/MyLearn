let todoInput = document.getElementById('todoInput');
let add = document.getElementById('add');
let todoList = document.getElementById('todoList');

add.addEventListener("click", function () {
    if (todoInput.value == 0) {
        alert("请输入内容");
    }
    else {
        const todo = document.createElement('p');
        todo.innerText = todoInput.value.trim();
        todoList.appendChild(todo);
        const delet = document.createElement('button');
        delet.innerText = "删除";
        todo.appendChild(delet);
        const hr = document.createElement('hr');
        todo.appendChild(hr);
        delet.id = "delet";
        todoInput.value = "";
        delet.addEventListener("click", function () {
            todoList.removeChild(todo);
            todoList.removeChild(delet);
            todoList.removeChild(hr);
        })
    }
})

