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
**1. QT 5.12.9** (it's ok to configure your own version)<br>
[**2. OpenMVG**](https://github.com/openMVG/openMVG)(it's not needed now)<br>
[**3. OpenMVS**](https://github.com/cdcseacave/openMVS)(it's not needed now)<br>

# Schedule
2021-6-16: <br>
Completed works :
1. Image zooming and moving with mouse interaction
2. Images' previews
3. Windows' size adaptation

![image](https://user-images.githubusercontent.com/62642008/122242616-0d93d180-cef6-11eb-873f-7122992d92d5.png)

2021-6-11: <br>
Completed works : 
1. loading images and displaying them.<br>

# Blogs
If you are a Chinese, welcome to fllow my blog : [https://blog.csdn.net/rs_lys](https://blog.csdn.net/rs_lys)
