# StuManagement

## 测试用例：
- 管理员 账号LHJ 密码123
  - 登录后可以加学生成绩、查询所有成绩、排序、按照学号和姓名进行查找、可以修改学生成绩
- 普通用户  账号ABC 密码123  验证学号为09017334
  - 登录后验证了学号可以进去学生系统，暂时的功能为查询个人成绩
- 还可以加上选课系统（但有点麻烦
- 现在代码量估计是600+

## how to use
源代码通过打开外面的management.sln打开解决方案可以运行debug模式
最后的可执行文件在最外面的release文件夹下
成绩相关信息表 GradeRecord.txt 


## 添加了功能：
- 管理员选择添加书籍，输入书籍名称可以进行添加
- 用户可以进行借阅书籍，查询自己已经借的书，可以进行归还书
- 且多个用户可以进行借书，即其他人借了书，另一个用户登录还可以借
- 用户所借的书与用户一一对应起来，保存在BookBorrowedRecord.txt
- 书籍信息以及状态保存在BookRecord.txt

## screens
![sc1](./Management/sc1.png)

![sc2](./Management/sc2.png)
