//开局自动切换背景图片
const bgcImg=document.querySelector('.large')
const img1=document.querySelector('.small>ul>li:nth-child(1)')
console.log(img1.children[0].getAttribute('src'))
const src =img1.children[0].getAttribute('src')
console.log(bgcImg.style.backgroundImage)
// document.getElementById ("img").src="/after.jpg"
// bgcImg.style.backgroundImage=`url()`
// console.log(111)
// 商品栏细节
// 四张商品图点击选中
// 将选中图片展示在左边盒子
const bigImg = document.querySelector('.xtx-product-info .left .picture .middle img')
const ul = document.querySelector('.small ul')
ul.addEventListener('mouseover', function (e) {
  if (e.target.tagName === 'IMG') {
    const active = document.querySelector('ul .active')
    active.classList.remove('active')
    e.target.parentNode.classList.add('active')
    // console.log(e.target.src)

    bigImg.src = e.target.src
  }
})
// 颜色选中效果
const dd2 = document.querySelector('.attrs .item:nth-child(2) .dd')
dd2.addEventListener('click', function (e) {
  if (e.target.tagName === 'SPAN') {
    const active = document.querySelector('.dd .active')
    if (active) active.classList.remove('active')
    e.target.classList.add('active')
  }
  console.log('11')
})
// 商品数量增加效果
// const num3 = document.querySelector('.attrs .item:nth-child(3) .dd .num')
// num3.children[0].addEventListener('click', function () {
//   let number = num3.children[1].valueu
//   if (number > 1) {
//     number--
//     num3.children[1].value = number
//   }
// })
// num3.children[2].addEventListener('click', function () {
//   let number = num3.children[1].value

//   number++
//   num3.children[1].value = number
// })
// 放大镜效果
// 鼠标经过左边盒子，显示右边盒子
const left = document.querySelector('.middle')
const right = document.querySelector('.large')
let timeout = 0
function show() {
  clearTimeout(timeout)
  right.style.display = 'block'
  right.style.backgroundImage = `url(${left.children[0].src})`
}
function hide() {
  timeout = setTimeout(() => {
    right.style.display = 'none'
  }, 200);

}
left.addEventListener('mouseenter', show)
left.addEventListener('mouseleave', hide)
right.addEventListener('mouseenter', show)
right.addEventListener('mouseleave', hide)
// 鼠标进入左边盒子，显示黑色遮罩盒子
const black = document.querySelector('.layer')
left.addEventListener('mouseenter', function () {
  black.style.display = 'block'
})
left.addEventListener('mouseleave', function () {
  black.style.display = 'none'
})
// 黑色遮罩层跟随鼠标移动
left.addEventListener('mousemove', function (e) {
  let x = e.pageX - left.getBoundingClientRect().left - document.documentElement.scrollLeft
  let y = e.pageY - left.getBoundingClientRect().top - document.documentElement.scrollTop
  if (x >= 100 && x <= 300) {
    black.style.marginLeft = `${x - 100}px`
  }
  if (x < 100) {
    black.style.marginLeft = `s0px`
  }
  if (x > 300) {
    black.style.marginLeft = `200px`
  }
  if (y >= 100 && y <= 300) {
    black.style.marginTop = `${y - 100}px`
  }
  if (y < 100) {
    black.style.marginTop = `s0px`
  }
  if (y > 300) {
    black.style.marginTop = `200px`
  }
  // 右边盒子放大效果
  let rx = black.getBoundingClientRect().left - left.getBoundingClientRect().left
  let ry = black.getBoundingClientRect().top - left.getBoundingClientRect().top
  rx = -2 * rx + 'px'
  ry = -2 * ry + 'px'
  right.style.backgroundPositionX = rx
  right.style.backgroundPositionY = ry
})
// 返回商品列表界面
const back = document.querySelector('.back')
back.addEventListener('click', function () {
  window.history.back()
})

//收藏按钮功能
//封装函数

//按钮变色
const buyBtn = document.querySelector('.buy')
let flag = true
buyBtn.addEventListener('click', () => {
  if (flag) {
    buyBtn.textContent = `取消收藏`
    buyBtn.style.backgroundColor = `skyblue`
    flag = false
    const n = document.querySelector('.item_buy .active')
    if (n) n.classList.remove('active')
    document.querySelector('.collect_success').classList.add('active')
  }
  else {
    buyBtn.textContent = `立即收藏`
    buyBtn.style.backgroundColor = `rgb(0, 183, 255)`
    flag = true
    const n = document.querySelector('.item_buy .active')
    if (n) n.classList.remove('active')
    document.querySelector('.collect_defeat').classList.add('active')
  }
})
buyBtn.addEventListener('mouseout', () => {
  const n = document.querySelector('.item_buy .active')
  if (n) n.classList.remove('active')
})
