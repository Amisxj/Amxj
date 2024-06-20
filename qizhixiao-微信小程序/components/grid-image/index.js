// components/grid/index.js
Component({

  externalClasses: ['i-class'],
  relations: {
    '../grid-item-image/index': {
      type: 'child',
      linked() {
        //当grid-item插入时
        this.setGridItemWidth()
      },
      linkChange() {
        //当grid-item移动时
        this.setGridItemWidth()
      },
      unlinked() {
        //当grid-item移除时
        this.setGridItemWidth()
      }
    }
  },
  /**
   * 组件的属性列表
   */
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
      const nodes = this.getRelationNodes('../grid-item-image/index');
      console.log(nodes.length)
      const width = 100 / 3
      nodes.forEach(item => {
        if (item.data.type === 'single'){
          item.setData({
            'width': '100%'
          })
        } else if (item.data.type === 'double'){
          item.setData({
            'width': '50%'
          })
        }else{
          item.setData({
            'width': width + '%'
          })
        }
      })
    }
  },
  // 在组件实例刚刚被创建的时候执行
  create: function(){

  },
  // 在组件实例进入节点树时执行
  attached: function(){

  },
  // 在组件在视图层布局完成时执行
  ready: function(){
    this.setGridItemWidth()
  },
  // 在组件实例被移动到节点树的另一个位置的时候
  moved: function(){

  },
  // 在组件实例从页面中移除的时候
  detached: function(){

  },
  // 当组件文件方法抛出异常时执行
  error:function(){

  }
})
