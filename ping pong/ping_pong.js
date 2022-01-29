const can = document.getElementById("table");
const draw_ = can.getContext("2d");

const ball={
    x:can.width/2,
    y:can.width/2,
    radius:15,
    velX:5,
    velY:5,
    speed:5,
    color:"white"
}

const user={
    x:0,
    y:(can.height-100)/2,
    width:10,
    height:100,
    score:0,
    color:"white"
}

const cpu={
    x:can.width-10,
    y:(can.height-100)/2,
    width:10,
    height:100,
    score:0,
    color:"white"
}

const sep={
    x:(can.width-2)/2,
    y:0,
    height:10,
    width:3,
    color:"white"
}

function drawRectangle(x,y,w,h,color)
{
    draw_.fillStyle = color;
    draw_.fillRect(x,y,w,h);
}

function drawCircle(x,y,r,color)
{
    draw_.fillStyle = color;
    draw_.beginPath();
    draw_.arc(x,y,r,0,Math.PI*2,false);
    draw_.closePath();
    draw_.fill();
}

function drawScore(test,x,y)
{
    draw_.fillStyle = "white";
    draw_.font="75px fantasy";
    draw_.fillText(test,x,y);
}

function drawSeparator()
{
    for(let i=0; i<=can.height; i+=15)
    {
        drawRectangle(sep.x,sep.y+i,sep.width,sep.height,sep.color);
    }
}

function restart()
{
    ball.x=can.width/2;
    ball.y=can.height/2;
    ball.velX=-ball.velX;
    ball.speed=5;
}

function detect_collision(ball,player)
{
    player.top = player.y;
    player.bottom = player.y + player.height;
    player.left = player.x;
    player.right = player.x + player.width;

    ball.top = ball.y - ball.radius;
    ball.bottom = ball.y + ball.radius;
    ball.left = ball.x - ball.radius;
    ball.right = ball.x + ball.radius;

    return ball.right > player.left && ball.top < player.bottom && ball.left < player.right && ball.bottom > player.top;
}

can.addEventListener("mousemove",getMousePos);

function getMousePos(evt)
{
    let rect = can.getBoundingClientRect();
    user.y = evt.clientY-rect.top-user.height/2;
}

function helper()
{
    drawRectangle(0,0,can.width,can.height,"black");
    drawScore(user.score,can.width/4,can.height/5);
    drawScore(cpu.score,3*can.width/4,can.height/5);

    drawSeparator();
    
    drawRectangle(user.x,user.y,user.width,user.height,user.color);
    drawRectangle(cpu.x,cpu.y,cpu.width,cpu.height,cpu.color);
    drawCircle(ball.x,ball.y,ball.radius,ball.color);
}

function updates()
{
    if(ball.x-ball.radius<0)
    {
        cpu.score++;
        restart();
    }
    else if(ball.x+ball.radius >can.width)
    {
        user.score++;
        restart();
    }

    ball.x += ball.velX;
    ball.y += ball.velY;

    let level=0.1;
    cpu.y+=(ball.y - (cpu.y + cpu.height/2))* level;

    if((ball.y-ball.radius<0) || (ball.y+ball.radius>can.height))
    {
        ball.velY = -ball.velY;
    }

    let player = (ball.x < can.width/2) ? user:cpu;
    
    if(detect_collision(ball,player))
    {
        let collidepoint = (ball.y - (player.y+ player.height/2));
        collidepoint = collidepoint/(player.height/2);
        let angleRad = (Math.PI/4)* collidepoint;

        let direction = (ball.x < can.width/2) ? 1 : -1;
        ball.velX = direction*ball.speed*Math.cos(angleRad);
        ball.velY = direction*ball.speed*Math.sin(angleRad);
        ball.speed+=0.5;
    }
}

function call_back()
{
    updates();
    helper();
}

let fPS=50;
setInterval(call_back,1000/fPS);