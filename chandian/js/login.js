const choose = document.querySelector('.enter .choose')
const user = document.querySelector('.enter>.user')
const rooter = document.querySelector('.enter>.rooter')
choose.addEventListener('click', function (e) {
  if (e.target.tagName === 'P') {
    const n = document.querySelector('.enter .choose .active')
    if (n) n.classList.remove('active')
    e.target.classList.add('active')
    document.getElementById('enterForm').reset()
  }
})
document.querySelector('.choose .user').addEventListener('click', function () {
  user.style.display = 'block'
  rooter.style.display = 'none'
})
document.querySelector('.choose .rooter').addEventListener('click', function () {
  user.style.display = 'none'
  rooter.style.display = 'block'
})
const back = document.querySelector('.top .top_back')
back.addEventListener('click', function () {
  window.location.href = 'index.php'
})