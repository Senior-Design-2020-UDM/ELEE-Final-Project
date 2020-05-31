s = serial('/dev/cu.usbmodem141401');  
set(s,'BaudRate',9600);  
fopen(s);  
fileID = fopen('/Users/chenjiajun/Library/Mobile Documents/com~apple~CloudDocs/HomeWork_UDM/2020 Winter/Seneior Design/Wifi_Final/IRtest/USBData.txt','a'); 

interval = 3; 
c = 1;
counter = 1;

dateString = date;
fprintf(fileID,'%s\n',dateString);

while(counter<interval)
    b = fgetl(s);  
    fprintf(fileID,'%s',b);
    counter = counter+ c;
end

fclose(fileID);
fclose(s);
