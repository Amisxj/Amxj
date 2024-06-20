// components/col/index.js
Component({
  /**
   * 组件的属性列表
   */
  externalClasses:['i-class'],
  relations: {
    '../row/index':{
      type:'parent'
    }
  },

  properties: {
    span:{
      value:0,
      type:Number
    },
    offset:{
      value:0,
      type:Number
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

  }
})