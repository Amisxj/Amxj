// components/grid/index.js
Component({
  /**
   * 组件的属性列表
   */
  externalClasses:['i-class'],

  relations:{
    '../grid-item/index':{
      type:'child',
      // 插入项目
      linked(){
        this.setGridItemWidth()
      },
      // 移动项目
      linkChanged(){
        this.setGridItemWidth()
      },
      // 删除项目
      unlinked(){
        this.setGridItemWidth()
      }
    }
  },

  properties: {

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
    setGridItemWidth(){
      const nodes = this.getRelationNodes("../grid-item/index")
      const width = 100/nodes.length
      nodes.forEach(item => {
        item.setData({
          'width': width + '%'
        })
      })
    }
  },
  // 创建组件实例时
  create: function(){

  },
  // 进入节点数执行
  attached: function(){

  },
  // 在视图层完成执行
  ready: function(){
    this.setGridItemWidth()
  },
  // 在组件实例被移动到节点树另一个位置时
  moved: function(){

  },
  // 在组件实例被移除时侯
  detached: function(){

  },
  // 当组件文件错误时
  error: function(){

  }
})