# project_camke
日常的开发有如下需求：

1. 开发的平台经常更换，有时使用st的芯片，有时使用nxp的芯片，还有国产的芯片等，这些开发平台是经常需要改变。使用这些芯片的时候，我要使用他们的外设接口（如 spi i2c uart ）去操作各种传感器。各种传感器都各种类型品牌，比如加速传感器就有几十种，经常需要测试那种比较好和便宜，各种传感器芯片都要编写一个测试单元去测试，除了板载的测试，我们还需要经常网络的测试，各种类型库的测试，，最终单元测试完成后才能加入我的源码中，进行商务逻辑编写。
2. 在开发过程中，难免会使用一些库，比如mqtt，curl，json等
3. 经常会使用交叉编译工具链编译之后传到对应的硬件平台。这里弄一个编译之后自动传到对应的脚本

## 1.2 工程目录说明
```
1.bin
	该目录存放着程序的执行文件，如单元测试的执行文件以及总工程项目的执行文件。

2.build
	该目录存放CMake构建后的缓存文件。

3.cmake_config
	该目录存放CMake的配置文件。

4.doc
	该目录存放工程相关说明文档。

5.script
	该目录存放其他辅助的脚本。

6.source
	该目录存放主体业务源码。

7.third_lib
	该目录存放第三方使用的库。

8.unit_test
	该目录存放单元测试工程。

9.CMakeLists.txt
    总工程构建CMake文件。

10.build.sh
    总工程编译脚本文件。

11.buildcfg
    build.sh的配置文件。

12. log
    存放修改的详细内容
```


# buildcfg说明
```
login_user=xxx   #要传到对应板子上的ssh账号
login_pswd=xxx   #要传到对应板子上的ssh密码
login_host=192.168.2.161 #要传到对应板子上对应的ip
exe_bin=xxx #要传到对应板子上可执行程序
dest_path=xxx #传到板子上的那个位置
```