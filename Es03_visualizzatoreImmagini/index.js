"use strict"

$(document).ready(function(){
    let progressivo = 1;
    $("#btnAvanti").css({
        backgroundColor : "orange",
        width : "160px",
        height: "40px",
        textAlign : "center",
        borderRadius : "40%",
        fontWeight : "bold",
        margin : "20px 10px" // non si mette niente alla fine dell l ultima istruzione, 
        //si mette vigola per istruzioni
    })

    $("#btnIndietro").css({
        backgroundColor : "orange",
        width : "160px",
        height: "40px",
        textAlign : "center",
        borderRadius : "40%",
        fontWeight : "bold",
        margin : "20px 10px"
    })

    $("#btnIndietro").prop("disabled","true"); //true lo accetta sia come stringa che come 
    //boolean

    $("#img").prop("src","img/img1.jpg").css({//metodi a cascata
        width:"400px",
        height:"400px",
        verticalAlign:"middle" // come allineare con margin 0 auto ma n vertical
    })

    $("#btnAvanti").on("click",function(){
        progressivo++;
        $("#img").prop("src","img/img" + progressivo +".jpg") // posso fare piu . prop() 
        //perche le propieta non si cancellano
        if(progressivo==7){
            $("#btnAvanti").prop("disabled",true)
        }
        $("#btnIndietro").prop("disabled",false)
    })

    $("#btnIndietro").on("click",function(){
        progressivo--;
        $("#img").prop("src","img/img" + progressivo +".jpg") // posso fare piu . prop() 
        //perche le propieta non si cancellano
        if(progressivo==1){
            $("#btnIndietro").prop("disabled",true)
        }
        $("#btnAvanti").prop("disabled",false)
    })



});