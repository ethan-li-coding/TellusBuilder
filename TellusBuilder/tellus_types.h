#ifndef TELLUS_BUILDER_TYPES_H
#define TELLUS_BUILDER_TYPES_H

// system-library
#include <string>
#include <vector>
using std::vector;
using std::string;

namespace tellus {
class Image
{
public:
	Image() = default;
	~Image() = default;

	Image(const string& _path, const unsigned& _id) :path_(_path), id_(_id) {
		// get name from path
		auto pos = path_.find_last_of('\\') + 1;
		if (pos == 0) {
			pos = path_.find_last_of('/') + 1;
		}
		name_ = path_.substr(pos, path_.length() - pos);
		pos = name_.find_last_of('.');
		name_ = name_.substr(0, pos);
	}

	/** set id of belonging camera*/
	void set_cam_id(const unsigned& _id) {
		cam_id_ = _id;
	}
	/** get path */
	const string& get_path() {
		return path_;
	}
	/** get name */
	const string& get_name() {
		return name_;
	}
	/** get id */
	const unsigned& get_id() {
		return id_;
	}
	/** get camera id */
	const unsigned& get_cam_id() {
		return cam_id_;
	}
	
private:
	string path_;		// path
	string name_;		// name
	unsigned id_;		// id
	unsigned cam_id_;	// id of camera
};
}

using namespace tellus;

#endif
