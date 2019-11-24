function showProperty(data) {
    let $popup = $("#popup");

    // if not popup element, create it
    if(!$popup.length) {
        let container = $("" +
            "<div id='popup'>" +
            "   <div name='card'>" +
            "       <div name='title'>Precio Regular: $<span name='price'>0000</span></div><img src='img/close.png'>" +
            "       <div name='data'>" +
            "           <div name='name'>Nombre</div>" +
            "           <div name='alq-div'>Alquiler $<span name='alquiler'>000</span></div>" +
            "           <table>" +
            "               <tr name=\"price1\">" +
            "                   <td>" +
            "                       <img src=\"img/house.png\">" +
            "                   </td>" +
            "                   <td name=\"value\">$0000" +
            "                   </td>" +
            "               </tr>" +
            "               <tr name=\"price2\">" +
            "                   <td>" +
            "                       <img src=\"img/house.png\">" +
            "                       <img src=\"img/house.png\">" +
            "                   </td>" +
            "                   <td name=\"value\">$0000" +
            "                   </td>" +
            "               </tr>" +
            "               <tr name=\"price3\">" +
            "                   <td>" +
            "                       <img src=\"img/house.png\">" +
            "                       <img src=\"img/house.png\">" +
            "                       <img src=\"img/house.png\">" +
            "                   </td>" +
            "                   <td name=\"value\">$0000" +
            "                   </td>" +
            "               </tr>" +
            "               <tr name=\"price4\">" +
            "                   <td>" +
            "                       <img src=\"img/house.png\">" +
            "                       <img src=\"img/house.png\">" +
            "                       <img src=\"img/house.png\">" +
            "                       <img src=\"img/house.png\">" +
            "                   </td>" +
            "                   <td name=\"value\">$0000" +
            "                   </td>" +
            "               </tr>" +
            "               <tr name=\"price5\">" +
            "                   <td>" +
            "                       <img src=\"img/hotel.png\">" +
            "                   </td>" +
            "                   <td name=\"value\">$0000" +
            "                   </td>" +
            "               </tr>" +
            "           </table>" +
            "           <div name='hip-div'>Valor de la hipoteca $<span name='hipoteca'>000</span></div>" +
            "       </div>" +
            "   </div>" +
            "</div>");

        $("body").append(container);
        $popup = $(container);

        $("img[src='img/close.png']",container).click(function () {
            $popup.hide();
        });

    }

    let $name = $popup.find("[name='name']");
    $name.css("background-color", data.color);
    $name.text(data.name);

    $popup.find("[name='price']").text(data.price);

    $popup.show();

}

$(document).ready(function() {
    $(".property").click(function() {
        let index = parseInt(this.id);
        console.log(index);
        /*$.ajax({
            type: "POST",
            url: "/search",
            data:{
                op:"getPropertyData",
                id:index
            },
            success: function(data){
                let $res = $("#search-res");
                $res.empty();
                $res.html(data);
            }
        });*/

        let price = $(".price",this).text();
        price = price.substr(price.indexOf("$")+1);

        let data = {
            color: $(".color-bar",this).css("background-color"),
            name: $(".name",this).text(),
            price: price
        };

        showProperty(data);
    });
});