# #!/bin/bash
echo -n "login: "
#请添加代码，读取登录名
read name;
echo -n "password: "
#请添加代码，读取登陆密码
read passwd
if [ $name = "cht" -a $passwd = "abc" ];then
echo "the host and password is right!"
else echo "input is error!"
fi
