// pages/join/index.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    account:'',
    pass:'',
    repeatPass:'',
    visiDialog: false,
    validateCode:''
  },

  changeValidateCode(e){
    this.setData({
      validateCode:e.detail.detail.value
    })
  },
  confirmCode: function(){

  },
  cancelCode: function(){
    this.setData({
      visiDialog: false
    });
  },
  registerAction: function(){
    this.setData({
      visiDialog: true
    });
  },
  changeAccount:function(e){
    console.log("账号");
    this.setData({
      account:e.datail.detail.value
    });
  },
  changePass:function(e){
    console.log("密码");
    this.setData({
      pass:e.detail.detail.value
    });
  },
  changeRepeatPass:function(e){
    console.log("二次密码");
    this.setData({
      repeatPass:e.detail.detail.value
    });
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