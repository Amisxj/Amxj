
//导航栏搜索，关键词自动出现
const searchIpt = document.querySelector('.search input')
const rank = document.querySelector('.big .hot')
searchIpt.addEventListener('focus', function (e) {
  document.querySelector('.header .hotwords_rank').style.display = 'block'
})
// 点击热点关键词自动填入并搜索

document.querySelector('.header .hotwords_rank').addEventListener('click', function (e) {
  if (e.target.className === `tr`) {
    searchIpt.value = e.target.children[0].innerHTML
  }
  if (e.target.className === `rank_name`) {
    searchIpt.value = e.target.innerHTML
  }
  if (e.target.tagName === `IMG`) {
    searchIpt.value = e.target.parentNode.children[0].innerHTML
  }
  searchIpt.value = e.target.children[0].innerHTML
  localStorage.setItem('rank_name', searchIpt.value)
  document.querySelector('.header .hotwords_rank').style.display = 'none'
  window.location.href = 'search.php?search='+searchIpt.value
})
document.querySelector('.search button').addEventListener('click', function () {
  localStorage.setItem('rank_name', searchIpt.value)
  document.querySelector('.header .hotwords_rank').style.display = 'none'
  console.log(searchIpt.value)
  window.location.href = 'search.php?search='+searchIpt.value
})
//关闭热词
document.querySelector('.shortcut').addEventListener('click', function () {
  document.querySelector('.header .hotwords_rank').style.display = 'none'
})
document.querySelector('body .header').addEventListener('click', function (e) {
  if (e.target.tagName !== 'INPUT') {
    document.querySelector('.header .hotwords_rank').style.display = 'none'
  }
})
document.querySelector('.nav').addEventListener('click', function () {
  document.querySelector('.header .hotwords_rank').style.display = 'none'
})
document.querySelector('.footer').addEventListener('click', function () {
  document.querySelector('.header .hotwords_rank').style.display = 'none'
})

// 原点切换
// 封装函数
const returnTime = 2000 //轮播图切换时间
let i = 0
//函数封装
function render() {
  i++
  i > 4 ? i = 0 : i
  i < 0 ? i = 4 : i
  document.querySelector('.big .navigation .active').classList.remove('active')
  navLabs.children[i].classList.add('active')
  //图片自动变换
  document.querySelector('.big .nav-img .active').classList.remove('active')
  document.querySelector('.big .nav-img').children[i].classList.add('active')
}
const navLabs = document.querySelector('.big .navigation')
navLabs.addEventListener('click', function (e) {
  if (e.target.tagName === "LABEL") {
    i = e.target.dataset.navNumber - 1
    render()
  }
})
// 轮播图
let b = setInterval(render, returnTime)
//鼠标进入左右按键出来
const prev = document.querySelector('.big .nav-prev')
const current = document.querySelector('.big .nav-current')
document.querySelector('.nav-img').addEventListener('mouseenter', function () {
  clearInterval(b)
  console.log(1111)
  prev.style.display = 'block'
  current.style.display = 'block'
})
document.querySelector('.nav-img').addEventListener('mouseleave', function () {
  b = setInterval(render, returnTime)
  prev.style.display = 'none'
  current.style.display = 'none'
})
//点击左右按键切换图片
prev.addEventListener('click', () => {
  i--
  i--
  render()

})
current.addEventListener('click', () => {
  render()
})

