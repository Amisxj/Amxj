// components/modal/index.js
Component({
  /**
   * 组件的属性列表
   */
  externalClasses:['i-class'],

  relations:{
      '../grid/index':{
        type:'parent'
      },
  },

  properties: {
    visible:{
      type:Boolean,
      value:false
    },
    title: {
      type:String
    },
    showOk:{
      type:Boolean,
      value:true
    },
    showCancel:{
      type:Boolean,
      value:true
    },
    okText: {
      type:String,
      value:"确定"
    },
    cancelText: {
      type:String,
      value:"取消"
    }
  },

  /**
   * 组件的初始数据
   */
  data: {
  },

  /**
   * 组件的方法列表
   */
  methods: {
    handleClickOk(){
      this.triggerEvent('ok')
    },
    handleClickCancel(){
      this.triggerEvent('cancel')
    }

  }
})