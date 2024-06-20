// components/button/index.js
Component({
  /**
   * 组件的属性列表
   */
  externalClasses:['i-class'],

  properties: {
    type: {
      type:String,
      value:''
    },
    size: {
      type:String,
      value:''
    },
    shape: {
      type:String,
      value:'square'
    },
    disabled: {
      type:Boolean,
      value:false
    },
    long: {
      type:Boolean,
      value:false
    },
    loading: {
      type:Boolean,
      value:false
    },
    inline: {
      type:Boolean,
      value:false
    },
    hoverStartTime: {
      type:Number,
      value:20
    },
    hoverStayTime: {
      type:Number,
      value:40
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
    handleTap () {
      if(this.data.disabled) return false;
      this.triggerEvent("click");
    }
  }
})