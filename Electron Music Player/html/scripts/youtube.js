const electron = require('electron');
const $ = require('jquery');
const url = require('url');
const path = require('path');
const { BrowserWindow } = electron;

function playYoutubeFromLink() {
    var url = $("#link_holder").val();
    console.log(url);
    if(url != ''){
        var videoID = url.split("=")[1];
        $.getJSON('http://www.youtube.com/oembed?url=' + url + '&format=json', function(data, status) {
            if (status == 'success') {
                $("#link_paster").hide();
                $("#title").text(data.title);
                $("#author").text(data.author_name);
                $("#music_art").attr('src', data.thumbnail_url);
                $("#secondary_holder").append('<button class="btn mainback text-white d-inline" onclick="stopMusic()" role="button">Stop Music</button>')
                $("#invisible_player").attr('src', 'https://www.youtube.com/embed/' + videoID + '?autoplay=1');
            }
        });
    }else{
        alert('Empty URL');
    }
    
}


function stopMusic() {
    $("#invisible_player").attr('src', '');
    $("#music_art").attr('src', '');
    $("#title").hide();
    $("#author").hide();
    $("#secondary_holder").children('button').remove();
    $("#link_paster").show();
}


function closeYoutube() {

    var currentWindow = electron.remote.getCurrentWindow();

    currentWindow.loadURL(url.format({
        pathname: path.join(__dirname, 'index.html'),
        protocol: 'file:',
        slashes: true
    }));
}