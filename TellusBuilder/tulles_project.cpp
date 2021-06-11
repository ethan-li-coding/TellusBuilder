#include "tellus_project.h"

TellusProject::TellusProject()
{
}

TellusProject::~TellusProject()
{
}

bool TellusProject::AddImage(string img_path)
{
	all_images_.emplace_back(img_path, all_images_.size());

	return true;
}

const vector<Image>& TellusProject::GetAllImages()
{
	return all_images_;
}
