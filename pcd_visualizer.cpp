#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>
#include "Open3D/Open3D.h"

namespace fs = boost::filesystem;

int main (int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "ファイルまたはディレクトリを1つだけ指定してください" << std::endl;
        exit(EXIT_SUCCESS);
    }

    open3d::visualization::Visualizer visualizer;
    visualizer.CreateVisualizerWindow("Open3D", 1280, 720);

    fs::path path = argv[1];
    if (fs::is_directory(path)) {
        BOOST_FOREACH(const fs::path& p, std::make_pair(fs::directory_iterator(path), fs::directory_iterator())) {
            visualizer.AddGeometry(open3d::io::CreatePointCloudFromFile(fs::absolute(p).c_str()));
        }
    } else {
        visualizer.AddGeometry(open3d::io::CreatePointCloudFromFile(fs::absolute(path).c_str()));
    }

    visualizer.Run();
    visualizer.DestroyVisualizerWindow();

    return 0;
}