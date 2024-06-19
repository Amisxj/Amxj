function showAlert() {
    alert("尊敬的管理员，你好！");
    setTimeout(function() {
        // 这里是关闭提示框的代码
        window.history.go(0);
    }, 3000); // 这里设置的是3秒后关闭提示框，你可以根据需要调整这个值
}

// 调用函数
showAlert();
