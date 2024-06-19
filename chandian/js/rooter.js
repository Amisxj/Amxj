const choose = document.querySelector('.bottom .choose')
choose.addEventListener('click', function (e) {
  if (e.target.className === 'lis_text') {
    const n = document.querySelector('.choose .active')
    if (n) n.classList.remove('active')
    e.target.classList.add('active')
  }
  if (e.target.dataset.lisnum === '0') {
    console.log(1)
    goodsShow.style.display = 'block'
    goodsEnter.style.display = 'none'
  }
  if (e.target.dataset.lisnum === '1') {
    goodsShow.style.display = 'none'
    goodsEnter.style.display = 'block'
  }
})
const goodsShow = document.querySelector('.bottom>.goods')
const goodsEnter = document.querySelector('.bottom>.goods_enter')

// 返回登录界面
const back = document.querySelectorAll('[name="back"]')
for (let i = 0; i < back.length; i++) {
  back[i].addEventListener('click', function () {
    window.location.href = 'destroy.php'
  })
}
// 点击修改信息
const tab = document.querySelector('.goods table')
let flag=false
tab.addEventListener('click', function (e) {
  // 获取表单元素
  let form = document.getElementById("midifiedform");
  if (flag && e.target.className === 'goods_example')  {
    document.getElementById("midified").type ="submit"
    document.getElementById("midifiedform").submit();
  }else if (flag && e.target.className === 'goods_delete') {
    console.log('执行')
    console.log(document.getElementById("delete").type)
  }
  if( e.target.className === 'goods_delete' && !flag) {
    //获取序号id值改变form的地址给php页面
    let text = parseInt(e.target.parentNode.parentNode.children[0].textContent)
    // 更改表单的提交地址
    console.log(form.action)
    form.action = "delete.php?id=" + text;
    let yes = confirm("确认删除该数据!");
    if (yes === true) {
      //按钮名字改变
      e.target.innerHTML = `删除`
      e.target.style.backgroundColor = `red`
      flag = true
      console.log(flag)
      window.location.href="../delete.php?id="+text;
    }
  }else if(e.target.className === 'goods_example' && !flag){
    exampleImgSrc = e.target.parentNode.parentNode.children[1].children[0].src//得到要修改的图片的地址
    //获取序号id值改变form的地址给php页面
    let text =parseInt(e.target.parentNode.parentNode.children[0].textContent)
    // 更改表单的提交地址
    form.action = "midified.php?id="+text;
    console.log(form.action)
    content2 = e.target.parentNode.parentNode.children[2].innerHTML
    e.target.parentNode.parentNode.children[2].innerHTML = '<input name="name1" >'
    e.target.parentNode.parentNode.children[2].children[0].value = content2

    content3 = e.target.parentNode.parentNode.children[3].innerHTML
    e.target.parentNode.parentNode.children[3].innerHTML = '<select name="range1">\n' +
        '              <option>校园小卖部区</option>\n' +
        '              <option>校内区</option>\n' +
        '              <option>校门区</option>\n' +
        '              <option>校园周边区</option>\n' +
        '              <option>万达区</option>\n' +
        '            </select>\n'
    e.target.parentNode.parentNode.children[3].children[0].value = content3

    content4 = e.target.parentNode.parentNode.children[4].innerHTML
    e.target.parentNode.parentNode.children[4].innerHTML = '<input name="price1">'
    e.target.parentNode.parentNode.children[4].children[0].value = content4

    content5 = e.target.parentNode.parentNode.children[5].innerHTML
    e.target.parentNode.parentNode.children[5].innerHTML = '<input name="address1">'
    e.target.parentNode.parentNode.children[5].children[0].value = content5


    content6 = e.target.parentNode.parentNode.children[6].innerHTML
    e.target.parentNode.parentNode.children[6].innerHTML = '<input name="telephone1">'
    e.target.parentNode.parentNode.children[6].children[0].value = content6

    content7 = e.target.parentNode.parentNode.children[7].innerHTML
    e.target.parentNode.parentNode.children[7].innerHTML = '<select name="type1">\n' +
        '              <option>面食、粉食系列</option>\n' +
        '              <option>快餐小吃</option>\n' +
        '              <option>休闲甜点</option>\n' +
        '              <option>夜市系列</option>\n' +
        '            </select>'
    e.target.parentNode.parentNode.children[7].children[0].value = content7

    content8 = e.target.parentNode.parentNode.children[8].innerHTML
    e.target.parentNode.parentNode.children[8].innerHTML = '<input name="evaluate1">'
    e.target.parentNode.parentNode.children[8].children[0].value = content8
    //按钮名字改变
    e.target.innerHTML = `完成`
    e.target.style.backgroundColor = `red`
    console.log(document.getElementById("midified").type)
    flag = true
    console.log(flag)
  }
})

  function change(){
    //显示和隐藏修改按钮
    let button = document.getElementById('submit');
    let button1 = document.getElementById('cancel');
    if (button.style.display === 'none') {
      button.style.display = 'block';
    } else {
      button.style.display = 'none';
    }
    if (button1.style.display === 'none') {
      button1.style.display = 'block';
    } else {
      button1.style.display = 'none';
    }
  }

//点击修改图片
const exampleImg = document.querySelector('.example_img')
tab.addEventListener('click', function (e) {
  if (e.target.tagName === 'IMG' && flag) {
    exampleImg.style.display = `block`
    document.querySelector('.get_img>div>img').src = exampleImgSrc
    //图片预览处理
    const changeFile = document.getElementById('changeFile');
    const changeImage = document.getElementById('changImage');
    changeFile.addEventListener('change', function(e) {
      const file1 = e.target.files[0];
      const reader1 = new FileReader();
      reader1.onloadend = function() {
        changeImage.src = reader1.result;
      }
      if (file1) {
        reader1.readAsDataURL(file1);
      } else {
        changeImage.src = "";
      }
    });
    //表单数据
    let id = parseInt(e.target.parentNode.parentNode.children[0].innerHTML)
    let imgForm = document.getElementById("imgForm");
    // 更改表单的提交地址
    imgForm.action = "uploadimg.php?id="+id;
  }
})
const cancelBtn = document.querySelector('.example_button .btn2')
cancelBtn.addEventListener('click', () => {
  exampleImg.style.display = `none`

})

//点击刷新页面
function again(){
    location.reload();
}
