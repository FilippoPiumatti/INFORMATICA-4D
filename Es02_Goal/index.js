"use strict"
$(document).ready(function(){
    let _calciatore = $("#calciatore");
    let _palla  = $("#palla");

    _calciatore.hide();
    $("#esci").css("visibility","hidden");///equivalente a .hide();
    $("#fadeOut").css("visibility","hidden");
    $("#entra").on("click",function(){
        _calciatore.show(1000);
        $("#entra").hide();
        /*NOTA IMPORTATE
        Usare hide o usare .css(visibility) E la stessa identica  cosa*/ 
        $("#esci").css("visibility","visible");
        $("#fadeOut").css("visibility","visible");
    }) 

    $("#esci").on("click",function(){
        _calciatore.hide(800);
        $("#esci").css("visibility","hidden");
        $("#entra").show();
        $("#fadeOut").css("visibility","hidden");
    })


    /***************************/

    $("#fadeIn").click(function(){
        _calciatore.fadeIn(2000);
        $("#fadeIn").hide();
        /*NOTA IMPORTATE
        Usare hide o usare .css(visibility) E la stessa identica  cosa*/ 
        $("#fadeOut").css("visibility","visible");
    })

    $("#fadeOut").click(function(){
        _calciatore.fadeOut(2000);
        $("#fadeOut").css("visibility","hidden");
        $("#fadeIn").show();
    })


    /************************************************/

    $("#slideUp").click(function(){
        _palla.slideUp(1000);
    })

    $("slideDown").click(function(){
        _palla.slideDown(1000);
    })

    //NOTA IMPORTANTE: SCRIVERE .click oppure .on("click") è la STESSA cosa


    /*************************************************/


    $("#tira").on("click",function(){
        _palla.animate({left:"1025px",top:"300px",width:"50px",height:"50px"},1500,function(){
            alert("GOALLLLL!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
        });//modifico il css nel fine di creare una sorta di animazione
    })


    /**************************************************/

    $("#giallo").on("click",function(){
        _palla.prop("src","img/PalloneGiallo.jpg")
    })

    $("#rosso").on("click",function(){
        _palla.prop("src","img/PalloneRosso.jpg")
    })
});