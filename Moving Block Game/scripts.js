var redPiece, bluePiece;
var width =100;
var status ="no";

function startGame() {
    myGameArea.start();
    redPiece = new component(100, 100, "red", 100, 120);
    bluePiece = new component(100, 100, "blue", 400, 380);
}

var myGameArea = {
    canvas : document.createElement("canvas"),
    start : function() {
        this.canvas.width = 600;
        this.canvas.height = 600;
        this.context = this.canvas.getContext("2d");
        document.body.insertBefore(this.canvas, document.body.childNodes[0]);
        this.interval = setInterval(updateGameArea, 20);
        window.addEventListener('keydown', function (e) {
            myGameArea.key = e.keyCode;
        })
        window.addEventListener('keyup', function (e) {
            myGameArea.key = false;
        })
    }, 
    clear : function(){
        this.context.clearRect(0, 0, this.canvas.width, this.canvas.height);
    }
}

function component(width, height, color, x, y) {
    this.gamearea = myGameArea;
    this.width = width;
    this.height = height;
    this.speedX = 0;
    this.speedY = 0;    
    this.x = x;
    this.y = y;    
    this.update = function() {
        ctx = myGameArea.context;
        ctx.fillStyle = color;
        ctx.fillRect(this.x, this.y, this.width, this.height);
    }
    this.newPos = function() {
        this.x += this.speedX;
        this.y += this.speedY;
        
        if(this.x > 500) {
            this.speedX = 0;
            this.x = 500;
        }
        if(this.x < 0) {
            this.speedX = 0;
            this.x = 0;
        }
        if(this.y > 500) {
            this.speedY = 0;
            this.y = 500;
        }
        if(this.y < 0) {
            this.speedY = 0;
            this.y = 0;
        }
    }
}

function updateGameArea() {
    myGameArea.clear();
    redPiece.speedX = 0;
    redPiece.speedY = 0;    
    if (myGameArea.key && myGameArea.key == 37) {
        if(status === "collide"){redPiece.speedX = 2;}
        else {redPiece.speedX = -1;} 
    }
    if (myGameArea.key && myGameArea.key == 39) {
        if(status === "collide"){redPiece.speedX = -2;}
        else {redPiece.speedX = 1;}
    }
    if (myGameArea.key && myGameArea.key == 38) {
        if(status === "collide"){redPiece.speedY = 2;}
        else {redPiece.speedY = -1;}
    }
    if (myGameArea.key && myGameArea.key == 40) {
        if(status === "collide"){redPiece.speedY = -2;}
        else {redPiece.speedY = 1;}
    }
    redPiece.newPos(); 
    redPiece.update();
        
    bluePiece.speedX = 0;
    bluePiece.speedY = 0;    
    if (myGameArea.key && myGameArea.key == 65) {
        if(status === "collide"){bluePiece.speedX = 2;}
        else{bluePiece.speedX = -1;}
    }
    if (myGameArea.key && myGameArea.key == 68) {
        if(status === "collide"){bluePiece.speedX = -2;}
        else{bluePiece.speedX = 1;}
    }
    if (myGameArea.key && myGameArea.key == 87) {
        if(status === "collide"){bluePiece.speedY = 2;}
        else{bluePiece.speedY = -1;}
    }
    if (myGameArea.key && myGameArea.key == 83) {
        if(status === "collide"){bluePiece.speedY = -2;}
        else{bluePiece.speedY = 1;}
    }
    bluePiece.newPos();    
    bluePiece.update();

   // console.log("redx:"+ redPiece.x + "redy: " + redPiece.y);
   // console.log("bluex:"+ bluePiece.x + "bluey: " + bluePiece.y);
    if(redPiece.x <= (bluePiece.x+width) && (redPiece.x+width) >= bluePiece.x && redPiece.y<=(bluePiece.y+width) && (redPiece.y+width)> bluePiece.y){
        status = "collide";
    }
    else { status= "no";}
    
}