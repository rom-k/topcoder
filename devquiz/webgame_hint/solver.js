var n = 0;
var element;
do {
  n++;
  element = document.getElementById('card' + n);
} while (element != null);
//alert('n=' + n);

var myevent = document.createEvent('MouseEvents');
myevent.initEvent('click', false, true);

var i = 0;
var hash = new Array();
var color;
do {
  element = document.getElementById('card' + i++);
  element.dispatchEvent(myevent);
  color = element.style.backgroundColor;
  //alert('A: i=' + (i - 1) + ' (' + color + ')');
  
  if (hash[color] != undefined) {
    element = document.getElementById('card' + hash[color]);
    element.dispatchEvent(myevent);
  }
  
  else {
    hash[color] = i - 1;
    
    element = document.getElementById('card' + i++);
    element.dispatchEvent(myevent);
    color = element.style.backgroundColor;
    //alert('B: i=' + (i - 1) + ' (' + color + ')');
    
    if (hash[color] != undefined) {
      element = document.getElementById('card' + (i - 1));
      element.dispatchEvent(myevent);
      
      element = document.getElementById('card' + hash[color]);
      element.dispatchEvent(myevent);
    }
    
    else {
      hash[color] = i - 1;
    }
  }
} while (i < n);

// var element = document.getElementById('card' + n);
// if (element == null) {
//   alert('Card element is not found. Check element id.');
// } else {
//   var myevent = document.createEvent('MouseEvents');
//   myevent.initEvent('click', false, true);
//   element.dispatchEvent(myevent);
//   alert('Card color is "' + element.style.backgroundColor + '".');
// }
