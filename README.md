# TellusBuilder
Build the world around you

# Hi
Hi, i'm doing one thing which i think is interesting in a certain sense. <br>
<br>
That is： **Building the world around you!**<br>
<br>
It's a hard thing obviously, but now i decide to start from a easy way. I will use **vs2019+QT+OpenMVG+OpemMVS** to build a visualized framework.<br>
<br>
The [OpenMVG](https://github.com/openMVG/openMVG) is a open Multiple View Geometry framework, providing an end-to-end 3D reconstruction from images framework compounded of libraries, binaries, and pipelines. which recovering camera poses and a sparse 3D point-cloud from an input set of images<br>
<br>
The [OpenMVS](https://github.com/cdcseacave/openMVS) is a library for computer-vision scientists and especially targeted to the Multi-View Stereo reconstruction community, aims at providing a complete set of algorithms to recover the full surface of the scene to be reconstructed. The input is a set of camera poses plus the sparse point-cloud and the output is a textured mesh.<br>
<br>
Our goal is outputing a 3d mesh with real texture from a set of images. Like this:
![image](https://user-images.githubusercontent.com/62642008/121713577-99c98180-cb0f-11eb-8391-dee367bd4d4c.png)

# Dependencies
**1. opencv 3.1.0**<br>
**2. Eigen 3.2.8**<br>
(you can download the above two from [https://download.csdn.net/download/rs_lys/14981085](https://download.csdn.net/download/rs_lys/14981085))<br>
**3. QT 5.12.9** (it's ok to configure your own version)<br>
[**4. OpenMVG**](https://github.com/openMVG/openMVG)<br>
[**5. OpenMVS**](https://github.com/cdcseacave/openMVS)<br>

# Schedule
2021-6-11: Completing work : loading images and displaying them.<br>
![image](https://user-images.githubusercontent.com/62642008/121714736-b87c4800-cb10-11eb-9104-4b323544e761.png)

# Blogs
If you are Chinese, you can fllow my blog : [https://blog.csdn.net/rs_lys](https://blog.csdn.net/rs_lys)
