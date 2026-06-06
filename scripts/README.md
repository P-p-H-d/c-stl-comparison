To update:

* run `make` to generate the examples and populates the 'external' folder
* run the following scripts to update the JSON files:

    export GITHUB_TOKEN=<my github token>
    script/update_lib_maintenance_json.py
    script/update_lib_metrics_json.py
    script/update_lib_project_lines_json.py

    lib-features.json and lib-containers.json are manually edited.

* run the following scripts to update the README from the JSON files:

    script/update_readme_feature_tables.py
    script/update_readme_maintenance_table.py
    script/update_readme_metrics.py
    script/update_readme_project_sizes.py
