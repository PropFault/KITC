#pragma once
#include <filesystem>
#include <utility>
#include <optional>
#include <fstream>
class Resource{
public:
    virtual std::unique_ptr<std::istream> read() = 0;
    virtual std::unique_ptr<std::ostream> write() = 0;
};

class FileResource : public Resource{
private:
    std::filesystem::path path;
public:
    explicit FileResource(std::filesystem::path path) : path(std::move(path)) {}

    [[nodiscard]]
    const std::filesystem::path &getPath() const {
        return path;
    }

    void setPath(const std::filesystem::path &path) {
        FileResource::path = path;
    }

private:
    std::unique_ptr<std::istream> read() override {
        return std::make_unique<std::ifstream>(this->path);
    }

    std::unique_ptr<std::ostream> write() override {
        return std::make_unique<std::ofstream>(this->path);
    }
};