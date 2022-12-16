cmake_minimum_required(VERSION 3.8)
project(littlevgl C CXX)

option(NEW_SCREEN "Match new screen coordinates" ON)

add_library(${PROJECT_NAME}
        SHARED
        lvgl/lv_core/lv_style.c
        lvgl/lv_core/lv_obj.c
        lvgl/lv_core/lv_vdb.c
        lvgl/lv_core/lv_indev.c
        lvgl/lv_core/lv_refr.c
        lvgl/lv_core/lv_group.c
        lvgl/lv_hal/lv_hal_tick.c
        lvgl/lv_hal/lv_hal_disp.c
        lvgl/lv_hal/lv_hal_indev.c
        lvgl/lv_misc/lv_color.c
        lvgl/lv_misc/lv_trigo.c
        lvgl/lv_misc/lv_anim.c
        lvgl/lv_misc/lv_ufs.c
        lvgl/lv_misc/lv_fs.c
        lvgl/lv_misc/lv_math.c
        lvgl/lv_misc/lv_mem.c
        lvgl/lv_misc/lv_task.c
        lvgl/lv_misc/lv_circ.c
        lvgl/lv_misc/lv_fonts/lv_font_symbol_10.c
        lvgl/lv_misc/lv_fonts/lv_font_dejavu_40.c
        lvgl/lv_misc/lv_fonts/lv_font_symbol_40.c
        lvgl/lv_misc/lv_fonts/lv_font_dejavu_30.c
        lvgl/lv_misc/lv_fonts/lv_font_dejavu_40_cyrillic.c
        lvgl/lv_misc/lv_fonts/lv_font_dejavu_40_latin_sup.c
        lvgl/lv_misc/lv_fonts/lv_font_dejavu_30_latin_sup.c
        lvgl/lv_misc/lv_fonts/lv_font_dejavu_10_cyrillic.c
        lvgl/lv_misc/lv_fonts/lv_font_dejavu_20_latin_sup.c
        lvgl/lv_misc/lv_fonts/lv_font_dejavu_20.c
        lvgl/lv_misc/lv_fonts/lv_font_dejavu_30_cyrillic.c
        lvgl/lv_misc/lv_fonts/lv_font_symbol_30.c
        lvgl/lv_misc/lv_fonts/lv_font_dejavu_10.c
        lvgl/lv_misc/lv_fonts/lv_font_symbol_20.c
        lvgl/lv_misc/lv_fonts/lv_font_dejavu_10_latin_sup.c
        lvgl/lv_misc/lv_fonts/lv_font_dejavu_20_cyrillic.c
        lvgl/lv_misc/lv_ll.c
        lvgl/lv_misc/lv_templ.c
        lvgl/lv_misc/lv_font.c
        lvgl/lv_misc/lv_area.c
        lvgl/lv_misc/lv_txt.c
        lvgl/lv_objx/lv_btnm.c
        lvgl/lv_objx/lv_sw.c
        lvgl/lv_objx/lv_btn.c
        lvgl/lv_objx/lv_chart.c
        lvgl/lv_objx/lv_page.c
        lvgl/lv_objx/lv_cont.c
        lvgl/lv_objx/lv_objx_templ.c
        lvgl/lv_objx/lv_img.c
        lvgl/lv_objx/lv_tabview.c
        lvgl/lv_objx/lv_ta.c
        lvgl/lv_objx/lv_ddlist.c
        lvgl/lv_objx/lv_list.c
        lvgl/lv_objx/lv_cb.c
        lvgl/lv_objx/lv_bar.c
        lvgl/lv_objx/lv_roller.c
        lvgl/lv_objx/lv_lmeter.c
        lvgl/lv_objx/lv_slider.c
        lvgl/lv_objx/lv_label.c
        lvgl/lv_objx/lv_cb.c
        lvgl/lv_objx/lv_kb.c
        lvgl/lv_objx/lv_led.c
        lvgl/lv_objx/lv_win.c
        lvgl/lv_objx/lv_line.c
        lvgl/lv_objx/lv_mbox.c
        lvgl/lv_objx/lv_gauge.c
        lvgl/lv_draw/lv_draw_rbasic.c
        lvgl/lv_draw/lv_draw_vbasic.c
        lvgl/lv_draw/lv_draw.c
        lvgl/lv_themes/lv_theme_mono.c
        lvgl/lv_themes/lv_theme.c
        lvgl/lv_themes/lv_theme_default.c
        lvgl/lv_themes/lv_theme_night.c
        lvgl/lv_themes/lv_theme_alien.c
        lvgl/lv_themes/lv_theme_zen.c
        lvgl/lv_themes/lv_theme_material.c
        lvgl/lv_themes/lv_theme_templ.c
        lv_drivers/display/fbdev.c
        lv_drivers/indev/evdev.c
        )

target_include_directories(
        "${PROJECT_NAME}"
        PRIVATE
        .
)

set_target_properties(
        "${PROJECT_NAME}"
        PROPERTIES
        CMAKE_CXX_STANDARD 14
        CMAKE_CXX_STANDARD_REQUIRED ON
        CMAKE_C_STANDARD 99
        CMAKE_C_STANDARD_REQUIRED ON
        POSITION_INDEPENDENT_CODE ON)

if (NEW_SCREEN)
    target_compile_definitions(
            "${PROJECT_NAME}"
            PRIVATE
            NEW_SCREEN=1
    )
endif()

if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    target_compile_options(
            "${PROJECT_NAME}"
            PRIVATE
            "-O0"
            "-g"
    )
elseif("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    target_compile_options(
            "${PROJECT_NAME}"
            PRIVATE
            "-O2"
    )
endif()

include(GNUInstallDirs)
install(
        TARGETS "${PROJECT_NAME}"
        EXPORT "${PROJECT_NAME}"
)
install(
        EXPORT "${PROJECT_NAME}"
        DESTINATION "lib/cmake/${PROJECT_NAME}"
        NAMESPACE "${PROJECT_NAME}::"
)
install(
        FILES
        lvgl/lvgl.h
        lv_drivers/indev/evdev.h
        lv_drivers/display/fbdev.h
        lvgl/lv_drv_conf.h
        lvgl/lv_conf.h
        lvgl/lv_ex_conf.h
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/lvgl"
)
install(DIRECTORY
        lvgl/lv_core/
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/lvgl/lv_core"
        FILES_MATCHING PATTERN "*.h"
)
install(DIRECTORY
        lvgl/lv_draw/
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/lvgl/lv_draw"
        FILES_MATCHING PATTERN "*.h"
)
install(
        DIRECTORY
        lvgl/lv_misc/
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/lvgl/lv_misc"
        FILES_MATCHING PATTERN "*.h"
)
install(
        DIRECTORY
        lvgl/lv_hal/
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/lvgl/lv_hal"
        FILES_MATCHING PATTERN "*.h"
)
install(
        DIRECTORY
        lvgl/lv_objx/
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/lvgl/lv_objx"
        FILES_MATCHING PATTERN "*.h"
)
install(
        DIRECTORY
        lvgl/lv_themes/
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/lvgl/lv_themes"
        FILES_MATCHING PATTERN "*.h"
)
install(
        FILES "${PROJECT_NAME}Config.cmake"
        DESTINATION "lib/cmake/${PROJECT_NAME}"
)
