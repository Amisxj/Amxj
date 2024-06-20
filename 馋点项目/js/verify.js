let canvas = document.createElement('canvas');
canvas.width = 100;
canvas.height = 30;

let one =0;
// 获取2D渲染上下文
const ctx = canvas.getContext('2d');

// 清除canvas
function clearCanvas() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);
}

// 生成随机数
function getRandomInt(min, max) {
    min = Math.ceil(min);
    max = Math.floor(max);
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

// 生成验证码图像
function generateCaptcha() {
    clearCanvas();

    // 设置字体大小和字体类型
    ctx.font = '20px Arial';

    // 生成一组随机数作为验证码
    one =Math.floor(Math.random()*10000);
    // 将验证码绘制到canvas上
    ctx.fillText(one, 10, 25);

    // 将canvas显示在页面上
    const img =document.getElementById("img");
    img.appendChild(canvas);
}

function justify(){
    const two = document.getElementById('rand').value;
    if (one == two){
        alert('可以')
    }else {
        alert('验证码输入错误');
    }
}
generateCaptcha();