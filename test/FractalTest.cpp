#include <renderer.hpp>
#include <gtest/gtest.h>

TEST(RenderFractalTest, set_Mandelbrot){
      	Plane plane(100,100);
	      int color_count;
	      c_keys* colors = package_colors(&color_count);
	      plane.color = colors[1].function;

	      plane.right = 0.13314;    // iteracja dojdzie do 100 . 
	      plane.left = -0.502371;
	      plane.up = 0.441829;
	      plane.down = -0.50754;
	      set_Mandelbrot( &plane );

	      for(int i = 0; i < 10000; i++)
	            ASSERT_EQ(plane.data[i], 0) << "Incorrectly filled in set Mandelbrot";


	      plane.right = 0.97923;    // iteracja dojdzie do 100 .
	      plane.left = -0.819686;
	      plane.up = 0.162952;
	      plane.down = -0.0381654;
	      set_Mandelbrot( &plane );

	      for(int i = 0; i < 10000; i++)
              ASSERT_EQ(plane.data[i], 0) << "Incorrectly filled in set Mandelbrot";


	      plane.right = -0.960886;   // iteracja nie dojdzie do 100 .
	      plane.left = -0.713451;
	      plane.up = 0.9024;
	      plane.down = 0.63383;
	      set_Mandelbrot( &plane );

	      for(int i = 0; i < 10000; i++)
              ASSERT_NE(plane.data[i], 0) << "Incorrectly filled in set Mandelbrot";
} 

TEST(RenderFractalTest, Julia){
        Plane plane(100,100);
        int color_count; 
        c_keys* colors = package_colors(&color_count);
        plane.color = colors[1].function;

        plane.left = -0.226374;    // iteracja dojdzie do 100 . 
        plane.right = 0.100098;
        plane.up = 0.151139;
        plane.down = -0.115112; 
        set_Julia( &plane );

        for(int i = 0; i < 10000; i++) 
          ASSERT_EQ(plane.data[i], 0) << "Incorrectly filled in Julia";


        plane.left = -0.727927;    // iteracja dojdzie do 100 .
        plane.right = -0.49124;
        plane.up = 0.6257;
        plane.down = 0.448827;
        set_Julia( &plane );

        for(int i = 0; i < 10000; i++) 
          ASSERT_EQ(plane.data[i], 0) << "Incorrectly filled in Julia";


        plane.left = 0.0920798;   // iteracja nie dojdzie do 100 .
        plane.right = 0.251418;
        plane.up = 0.611065;
        plane.down = 0.453888;
        set_Julia( &plane );

        for(int i = 0; i < 10000; i++) 
          ASSERT_NE(plane.data[i], 0) << "Incorrectly filled in Julia";
}

TEST(RenderFractalTest,Cubic_Julia){
        Plane plane(100,100);
        int color_count;
        c_keys* colors = package_colors(&color_count);
        plane.color = colors[1].function;

        plane.left = -0.240693;    // iteracja dojdzie do 100 . 
        plane.right = 0.0939108;
        plane.up = 0.31227;
        plane.down = -0.138186;
        cubic_Julia( &plane );

        for(int i = 0; i < 10000; i++)
          ASSERT_EQ(plane.data[i], 0) << "Incorrectly filled in Cubic Julia";


        plane.left = 0.865722;    // iteracja dojdzie do 100 .
        plane.right = 0.958334;
        plane.up = -0.214756;
        plane.down = -0.375735;
        cubic_Julia( &plane );

        for(int i = 0; i < 10000; i++)
          ASSERT_EQ(plane.data[i], 0) << "Incorrectly filled in Cubic Julia";


        plane.left = 0.276878;   // iteracja nie dojdzie do 100 .
        plane.right = 0.342268;
        plane.up = 0.663704;
        plane.down = 0.531066;
        cubic_Julia( &plane );

        for(int i = 0; i < 10000; i++)
          ASSERT_NE(plane.data[i], 0) << "Incorrectly filled in Cubic Julia";
}

TEST(RenderFractalTest, Quadratur_Mandelbrot){
        Plane plane(100,100);
        int color_count;
        c_keys* colors = package_colors(&color_count);
        plane.color = colors[1].function;

        plane.left = -0.116403;    // iteracja dojdzie do 100 . 
        plane.right = 0.278476;
        plane.up = 0.405451;
        plane.down = -0.66813;
        Quadratur_Mandelbrot( &plane );

        for(int i = 0; i < 10000; i++)
          ASSERT_EQ(plane.data[i], 0) << "Incorrectly filled in Quadratur Mandelbrot";


        plane.left = -1.00056;    // iteracja dojdzie do 100 .
        plane.right = -0.871153;
        plane.up = 0.0699945;
        plane.down = -0.0979408;
        Quadratur_Mandelbrot( &plane );

        for(int i = 0; i < 10000; i++)
          ASSERT_EQ(plane.data[i], 0) << "Incorrectly filled in set Quadratur Mandelbrot";


        plane.left = -0.406489;   // iteracja nie dojdzie do 100 .
        plane.right = -0.265536;
        plane.up = -0.567689;
        plane.down = -0.752845;
        Quadratur_Mandelbrot( &plane );

        for(int i = 0; i < 10000; i++)
          ASSERT_NE(plane.data[i], 0) << "Incorrectly filled in set Quadratur Mandelbrot";
}

TEST(RenderFractalTest, Quadratur_Mandelbar){
        Plane plane(100,100);
        int color_count;
        c_keys* colors = package_colors(&color_count);
        plane.color = colors[1].function;

        plane.left = -0.228999;    // iteracja dojdzie do 100 . 
        plane.right = 0.129223;
        plane.up = 0.292173;
        plane.down = -0.292987;
        Quadratur_Mandelbar( &plane );

        for(int i = 0; i < 10000; i++)
          ASSERT_EQ(plane.data[i], 0) << "Incorrectly filled in set Quadratur_Mandelbar";


        plane.left = -0.347435;    // iteracja dojdzie do 100 .
        plane.right = -0.23591;
        plane.up = 0.943448;
        plane.down = 0.801615;
        Quadratur_Mandelbar( &plane );

        for(int i = 0; i < 10000; i++)
          ASSERT_EQ(plane.data[i], 0) << "Incorrectly filled in Quadratur_Mandelbar";


        plane.left = -0.00251743;   // iteracja nie dojdzie do 100 .
        plane.right = 0.195348;
        plane.up = 0.887746;
        plane.down = 0.551104;
        Quadratur_Mandelbar( &plane );

        for(int i = 0; i < 10000; i++)
          ASSERT_NE(plane.data[i], 0) << "Incorrectly filled in Quadratur_Mandelbar";
}
