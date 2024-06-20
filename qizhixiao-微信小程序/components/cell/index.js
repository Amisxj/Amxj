// components/cell/index.js
Component({

  externalClasses: ['i-class'],
  options: {
    mutipleSlots: true
  },
  relations: {
    '../cell-group/index':{
      type: 'parent'
    }
  },
  /**
   * 组件的属性列表
   */
  properties: {
    title: {
      type: String
    },
    label: {
      type: String
    },
    value: {
      type: String
    },
    isLink: {
      type: null,
      value: ''
    },
    onlyTopFooter:{
      type: Boolean
    },
    linkType: {
      type: String,
      value: 'navigateTo'
    },
    url: {
      type: String,
      value: ''
    }
  },

  /**
   * 组件的初始数据
   */
  data: {
    isLastCell: true
  },

  /**
   * 组件的方法列表
   */
  methods: {
    navigateTo(){
     const { url } = this.data;
     const type = typeof this.data.isLink;
     this.triggerEvent('click',{});
     if( !this.data.isLink || !url || url === 'true' || url === 'false') return;
     if(type !== 'boolean' && type !== 'string'){
       console.log('isLink 的属性必须是字符或者布尔表达式')
       return;
     }
     if(['navigateTo','redirectTo','switchTab','reLaunch'].indexOf(this.data.linkType) === -1){
       console.log("linkType 必须是'navigateTo','redirectTo','switchTab','reLaunch'中的一个")
        return;
     }
      wx[this.data.linkType].call(wx,{url});
    },
    handleTop(){
      if (!this.data.onlyTopFooter){
        this.navigateTo();
      }
    },
    updateIsLastCell (isLastCell){
      this.setData({isLastCell})
    }
  }
})
