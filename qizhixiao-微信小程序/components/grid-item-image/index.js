// components/grid-item/index.js
Component({
  /**
   * 组件的属性列表
   */
  externalClasses: ['i-class'],
  relations: {
    '../grid-image/index':{
      type: 'parent'
    },
    '../grid-icon/index': {
      type: 'child'
    },
    '../grid-label/index': {
      type: 'child'
    }
  },
  properties: {
    type: {
      type: String,
      value: ''
    }
  },

  /**
   * 组件的初始数据
   */
  data: {
    width: '33.33%',
    bg: '#fff'
  },

  /**
   * 组件的方法列表
   */
  methods: {
    touchStart(){
      this.setData({
        bg: '#ccc'
      })
    },
    touchEnd(){
      this.setData({
        bg: '#fff'
      })
    }
  }
})
