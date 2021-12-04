"use strict"
let prog = 1
$(document).ready(function(){
   $("#btnIndietro").hide(1000)
   $("#btnAvanti").hide(1000)
   $("#img").prop("src","img/img1.jpg").css({
       width:"400px",
       height:"400px"
   })

  
       
/*for (let index = 0; index < 7; index++) {
    $("#img").fadeOut(function(){
        prog++;
        $("#img").prop("src","img/img" + prog + ".jpg");
        $("#img").fadeIn(1000)
    });

    $("#img").fadeIn(function(){
        $("#img").prop("src","img/img" + prog + ".jpg");
        $("#img").fadeOut(1000);
    })
    
}*/
setInterval(function(){
    
    console.log(prog)
    $("#img").fadeOut(500,function(){
        prog++;
        
        $("#img").prop("src","img/img"+prog+".jpg")
        $("#img").fadeIn(500)
    })
    if(prog==7){
        prog = 0;
    }
     
},2000)
       
       
   
});