// pages/login/index.js
const {$Message} = require('../../components/base/index')

Page({

  /**
   * 页面的初始数据
   */
  data: {
    angle: 0
  },

  // 注册，找回密码
  toRegister: function() {
    wx.navigateTo({
      url: '../forget/index',
    })
  },
  toFindPass:function() {
    wx.navigateTo({
      url: '../join/index',
    })
  },
  // 登录
  goToIndex: function(){
    console.log("登录");
    $Message({
      content: '登录成功',
      type:'success'
    })
    wx.switchTab({
      url: '../playground/index',
    })
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad(options) {
    console.log("监听页面加载")
  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady() {
    console.log("监听页面初始化完成")
    // 水平仪
    let that = this
    wx.onAccelerometerChange(function(res){
      let angle =-(res.x *30).toFixed(1)
      if(angle > 20){
        angle = 20
      }else if(angle < -20){
        angle = -20
      }
      that.setData({
        angle:angle
      })
    })
  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow() {
    console.log("监听页面显示")
  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide() {
    console.log("监听页面隐藏")
  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload() {
    console.log("监听页面卸载")
    wx.stopAccelerometer({})
  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh() {
    console.log("监听页面下拉")
  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom() {
    console.log("监听页面触底")
  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage() {
    console.log("监听页面分享")
  }
})