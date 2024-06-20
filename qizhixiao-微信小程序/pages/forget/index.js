// pages/forget/index.js
Page({

  /**
   * 页面的初始数据
   */

  data: {
    account:'',
    paass:'',
    repeatPass:'',
    visiDialog:false,
    validateCate:''
  },
  comfirmCode:function(e){

  },
  cancelCode:function(e){
    this.setData({
      visiDialog:false
    })
  },
  forgetAction:function(e){
    this.setData({
      visiDialog:true
    })
  },
  changeAccount:function(e){
    this.setData({
      account:e.detail.detail.value
    })
  },
  changePass:function(e){
    this.setData({
      pass:e.detail.detail.value
    })
  },
  changeRepeatPass:function(e){
    this.setData({
      repeatPass:e.detail.detail.value
    })
  },
  changeValidateCode:function(e){
    this.setData({
      validateCode:e.detail.detail.value
    })
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad(options) {

  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady() {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow() {

  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide() {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload() {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh() {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom() {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage() {

  }
})