#Possible lua


Soon after all of our small goals are accomplished, scripts is our next target<br />

We will try out lua for this oppotunity<br />

Possible things in lua: <br />
    local console = StickOS:CreateConsole()
    console.Name = "asd"
    
    console:Send("echo hello world")
    console:Send("lua print('hi')")
    local key = console:WaitForKey("Wait message", 5000) If no key is pressed, it just returns something like [TIMEOUT] defaults to 100000000 or 1/0
    --o
    if (key ~= nil) then
        console:Send("We waited for your key: " .. key)
    else
        console:Send("You never entered a key :(")
    end 
    
    
    console:Stop() -- idk 
    
    
    
    
    
    
    
    

Probably will not come out for long time<br />

Documentation:

Functions:

