"use strict"
// 3 opzioni per fare un window.onload()

//1-
$(document).ready(function(){
      //function di callback: sono legate a certe funzioni, per esempio qua quando la pagina è pronta scatena la callback e tutte le istruzioni che ci sono dentro, quando è stata fatta la callback viene fatta una segnalazione di done
      let _lamp = $(".lampadina");
      let _desc = $("#descrizione");
      let _content = $("#contenuto");
  
      _lamp.hide();
  
      $("#btnAccendi").on("click",function(){
        _lamp.fadeIn(1000,function(){
              _lamp.addClass("accesa");
        })
      })
     
      $("#btnSpegni").on("click",function(){
          _lamp.removeClass("accesa");
      })
  
      /*accendiamo la lampadina in base al click su di essa..*/ 
      $("#imgLamp").on("click",function(){
         _lamp.toggleClass("accesa");
      })
  
      let descrizione = {
          width:"160px",
          height:"40px",
          "text-align":"center",
          lineHeight:"40px",
          backgroundColor:"#aaaaaa",
          textDecoration : "underline",
          fontSize:"16pt",
          cursor:"pointer",
          borderRadius:"15px",
          marginLeft:"50px"
      };
      //. css pu essere usata in due modi: 
      // 1- CI CREIAMO UN OGGETTO COME QUELLO SOPRA E GLIELO PASSIAMO COME PARAMETRO
      // 2- LA RISCRIVIAMO OGNI VOLTA
      _desc.css(descrizione);
      _content.css("width","600px");
      _content.css("border","2px solid red");
      _content.css("padding","10px");
      _content.css("border-radius" , "60px");
      _content.css("margin-top","30px");
      _content.css("margin-left","30px");
      _content.css("background-color","yellow")
  
      _content.hide();
  
      _desc.on("mouseover",function(){
          _content.slideDown(1000);
          _desc.off("mouseover");//contrario di on, toglie evento associato all oggetto
      })
      /*NOTA BENE: OGNI funzione jquery puo avere FUNZIONI DI CALLBACK*/ 
      _desc.on("mouseout",function(){
          /*_content.slideUp(1000,function(){
              _desc.on("mouseover",function(){
                  _content.slideDown(1000);
                  _desc.off("mouseover");//contrario di on, toglie evento associato all oggetto
                  _desc.on("mouseover",)
              })*/
              _content.slideUp(1000,function(){
                  _desc.on("mouseover",visualizzaContenuto);//forma escpilita di funzione
              })
          });
  
})
function visualizzaContenuto(){
   $("#contenuto").slideDown(1000);
    $("#descrizione").off("mouseover");//contrario di on, toglie evento associato all oggetto
}
  

//2-
/*
$(function(){
    alert("Pagina caricata con $(function(){})")
})*/

//3-
/*
$(()=>{
    alert("Caricamento con $(()=>{})");
})*/