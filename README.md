## ctf_vxworks   
**VxWorks弱hash算法碰撞**  
该实验主要完成了两件事：  
1) 通过编写程序获得长度为10的总计100万个随机密码的密码本；  
2) 通过编写程序使用密码本中密码碰撞出相同hash值的密码key值。  
  
**实验环境**  
Ubuntu 16.04  64位  
  
**代码说明**  
10pass.sh   随机生成长度为10的密码本  
运行方式： ./10pass.sh > 1.txt  
guesshash.c    碰撞hash值程序  
编译方式： gcc -o guesshash ./guesshash.c  
运行方式：./guesshash


