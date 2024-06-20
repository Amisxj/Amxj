// components/cell-group/index.js
Component({
  externalClasses: ['i-class'],
  relations:{
      '../cell/index': {
        type: 'child',
        linked (){
          this._updateIsLastCell();
        },
        linkChangeed(){
          this._updateIsLastCell();
        },
        unlinked() {
          this._updateIsLastCell();
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
    _updateIsLastCell(){
      let cells = this.getRelationNodes('../cell/index');
      const len = cells.length;
      if(len > 0){
        let lastIndex = len - 1;
        cells.forEach((cell , index) => {
          cell.updateIsLastCell(index === lastIndex)
        });
      }
    }
  }
})
