{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  name = "opengl-dev-env";

  # List of packages to include in the environment
  buildInputs = with pkgs; [
    # OpenGL libraries
    libGL
    libGLU
    freeglut
    glfw
    glew

    # Utilities and tools
    pkg-config
    cmake
    gcc
  ];

  # Environment variables
  shellHook = ''
    export LD_LIBRARY_PATH=${pkgs.libGL}/lib:${pkgs.glfw}/lib:${pkgs.glew}/lib:$LD_LIBRARY_PATH
    echo "OpenGL development environment ready!"
    echo "The path of libGL is: ${pkgs.libGL}/lib"
  '';
}
