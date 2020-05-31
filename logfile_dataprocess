fileID = fopen('/Users/chenjiajun/Library/Mobile Documents/com~apple~CloudDocs/HomeWork_UDM/2020 Winter/Seneior Design/Wifi_Final/Energy/USBData-1.txt','r');
formatSpec = '%s';
A = fscanf(fileID,formatSpec); 
dateFlag1 = '000000';
dateFlag2 = '000000';

filesize = length(A);
for i = 1:filesize
    if A(i) == 'r'
        if A(i+1) == 'e'
            if A(i+2) == 'a'
                readString = A(i+29);
                if readString == 'A'
                    LEDflag = 'G';
                end
                
                if readString == 'B'
                    LEDflag = 'Y';
                end
                
                if readString == 'C'
                    LEDflag = 'gy';
                end
                
                break;
            end
        end
    end
end

for i = 1:filesize
    if A(i) == 'S'
        if A(i+1) =='t'
            if A(i+2) == 'a'
                if A(i+13) == 'M'
                    dateFlag1 = A(i+10:i+15);
                    break;
                end
            end
        end
    end
end

for i = 1:filesize
    if A(i) == 'E'
        if A(i+1) =='n'
            if A(i+11) == 'M'
                dateFlag2 = A(i+8:i+13);
                break;
            end
        end
    end
end

x = [1:(str2num(dateFlag2(1:2))-str2num(dateFlag1(1:2))+1)];

for j = 1:(length(x)-1)
    y(j) = 0;
    for  i = 1:filesize
        if A(i)=='2'
            if A((i+7):(i+10))=='2020'
                if str2num(A(i+1))==(j-1)
                    if A(i+11) == LEDflag
                        if A(i+19) ~= '0'
                            if A(i+23) == '0'
                                y(j) = y(j) + str2num(A((i+19):(i+20)));
                            end
                            if A(i+24) == '0'
                                y(j) = y(j) + str2num(A((i+19):(i+21)));
                            end
                        end
                    end
                end
            end
        end
    end
end

j = length(x);
y(j) = 0;
for  i = 1:filesize
    if A(i)=='3'
        if A((i+7):(i+10))=='2020'
            if str2num(A(i+1))== 0
                if A(i+11) == LEDflag
                    if A(i+19) ~= '0'
                        if A(i+23) == '0'
                            y(j) = y(j) + str2num(A((i+19):(i+20)));
                        end
                        if A(i+24) == '0'
                            y(j) = y(j) + str2num(A((i+19):(i+21)));
                        end
                    end
                end
            end
        end
    end
end

plot(x,y,'b--','LineWidth',3);
title('LED Power Consumption');
xlabel('days');
ylabel('Energy');
grid on
