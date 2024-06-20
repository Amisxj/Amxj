// components/message/index.js
const defailt_date ={
  visible:false,
  content:'',
  duration:2,
  type:'default'    
}
let timmer = null;
Component({
  /**
   * 组件的属性列表
   */
  
  externalClasses:['i-class'],
  properties: {

  },

  /**
   * 组件的初始数据
   */
  data: {
    ...defailt_date
  },

  /**
   * 组件的方法列表
   */
  methods: {
    handleShow(options){
      const {type='default',duration=2}=options;
      this.setData({
        ...options,
        type,
        duration,
        visible:true
      });
      const d = this.data.duration * 1000 
      if(timmer) clearTimeout(timmer)
      if(d !==0 ){
        timmer = setTimeout(() =>{
          this.handleHide()
          timmer = null
        },d)
      }
    },
    handleHide(){
      this.setData({
        ...defailt_date
      })
    }
  }
})