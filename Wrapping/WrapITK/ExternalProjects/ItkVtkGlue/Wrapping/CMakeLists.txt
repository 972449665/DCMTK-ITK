find_package(WrapITK REQUIRED)

WRAP_LIBRARY("${PROJECT_NAME}")
  set(WRAPPER_SWIG_LIBRARY_FILES ${WRAPPER_SWIG_LIBRARY_FILES} "${CMAKE_CURRENT_SOURCE_DIR}/itkvtk.swg")
  set(WRAPPER_LIBRARY_DEPENDS VXLNumerics Base SimpleFilters Mesh)
  set(WRAPPER_LIBRARY_LINK_LIBRARIES ${ITK_LIBRARIES})

  if(WRAP_ITK_PYTHON)
    # I can't manage to put that code in Python subdir :-(
    set(VTK_VERSION "${VTK_MAJOR_VERSION}.${VTK_MINOR_VERSION}.${VTK_BUILD_VERSION}")
    set(MIN_ITK_VER "5.0.0")
    if("${VTK_VERSION}" STRLESS "${MIN_ITK_VER}")
      set(WRAPPER_LIBRARY_LINK_LIBRARIES ${WRAPPER_LIBRARY_LINK_LIBRARIES} vtkImagingPython)
    else("${VTK_VERSION}" STRLESS "${MIN_ITK_VER}")
      set(WRAPPER_LIBRARY_LINK_LIBRARIES ${WRAPPER_LIBRARY_LINK_LIBRARIES} vtkImagingPythonD)
    endif("${VTK_VERSION}" STRLESS "${MIN_ITK_VER}")

    subdirs(Python)
  else(WRAP_ITK_PYTHON)
    set(WRAPPER_LIBRARY_LINK_LIBRARIES ${ITK_LIBRARIES} vtkImaging vtkFiltering)
  endif(WRAP_ITK_PYTHON)

  if(WRAP_ITK_JAVA AND WRAPPER_LIBRARY_JAVA)
    set(WRAP_ITK_JAVA_USER_CLASS_PATH "${WRAP_ITK_JAVA_USER_CLASS_PATH}${VTK_LIBRARY_DIRS}/java/vtk.jar")#use NO space
    set(WRAP_ITK_JAVA_EXTENDED_JAVAIMPORTS "import vtk.*;")
  endif(WRAP_ITK_JAVA AND WRAPPER_LIBRARY_JAVA)

  AUTO_INCLUDE_MODULES()

END_WRAP_LIBRARY()
