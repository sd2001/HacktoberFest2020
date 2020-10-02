const fs = require('fs');
const $ = require('jquery');
const url = require('url');
const electron = require('electron');
const BrowserWindow = electron.remote.BrowserWindow;
const path = require('path');

function getMusic() {
    $("#music_list").children().remove();
    fs.readdir(__dirname + '../../../../music_goes_here', (error, file_names) => {
        if (error) {
            fs.mkdir(__dirname + '../../../../music_goes_here', (error) => {
                if (error) {
                    alert(error);
                }
            });
            alert('Place your music in the created folder');
        } else {

            if (file_names.length == 0) {
                alert('Empty Music Folder Detected');
            } else {
                var temp_id = 0;
                file_names.forEach(file_name => {

                    var file_name_extension_temp = file_name.split('.')[1];
                    if (file_name_extension_temp == 'mp3') {

                        $("#music_list").append('<li><a class="btn badge-pill mainback" id="mp3_id_' + temp_id + '"onclick=playMusic("mp3_id_' + temp_id + '")>' + file_name + '</a></li>')
                        temp_id++;
                    } else {
                        console.log(file_name + ' is not an mp3 file');
                    }
                });
            }
        }
    });
}

function playMusic(song_id) {
    $('#music_player').children().remove();
    var name = $("#" + song_id).text();
    $('#music_player').append('<audio controls><source src="' + __dirname + '../../../../music_goes_here/' + name + '" type="audio/mpeg"></source></audio>')
}


$("#switch-to-youtube").on('click', () => {

 

    $("#switch-to-youtube").removeClass('d-block');
    $("#switch-to-youtube").addClass('d-none');

    var currentWindow = electron.remote.getCurrentWindow();

    currentWindow.loadURL(url.format({
        pathname: path.join(__dirname, 'youtube.html'),
        protocol: 'file:',
        slashes: true
    }));

});